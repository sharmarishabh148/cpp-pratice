#define ALIGNMENT 8 // must be a power of 2
#define ALIGN(size) (((size) + (ALIGNMENT-1)) & ~(ALIGNMENT-1))

// blocks must be able to accommodate a free block header
#define MIN_BLK_SIZE ALIGN(sizeof(free_blk_header_t))
#define SIZE_T_SIZE (ALIGN(sizeof(size_t))) // header size

typedef struct free_blk_header
{
    size_t size;
    struct free_blk_header *next;
    struct free_blk_header *prior;
} free_blk_header_t;


// init heap with a permanent (circular) free list head
void init_heap()
{
    free_blk_header_t *bp = sbrk(ALIGN(sizeof(free_blk_header_t)));
    bp->size = 0;
    bp->next = bp;
    bp->prior = bp;
}


void *find_fit(size_t length)
{
    free_blk_header_t *bp = heap_start();
    for (bp = bp->next; bp != heap_start(); bp = bp->next)
    {
        // find first fit
        if (bp->size >= length)
        {
            // remove from free list and return
            bp->next->prior = bp->prior;
            bp->prior->next = bp->next;
            return bp;
        }
    }
    return NULL;
}


void *malloc(size_t size)
{
    static int heap_inited = 0;
    if (!heap_inited) {
        heap_inited = 1;
        init_heap();
    }
    size_t *header;
    int blk_size = ALIGN(size + SIZE_T_SIZE);
    blk_size = (blk_size < MIN_BLK_SIZE)? MIN_BLK_SIZE : blk_size;
    header = find_fit(blk_size);
    if (header)
    {
        *header = ((free_blk_header_t *)header)->size | 1;
        // *header = *header | 1; <-- also works (why?)
        // FIXME: split if possible
    }
    else
    {
        header = sbrk(blk_size);
        *header = blk_size | 1;
    }
    return (char *)header + SIZE_T_SIZE;
}

void free(void *ptr)
{
    free_blk_header_t *header = (char *)ptr - SIZE_T_SIZE,
                       *free_list_head = heap_start();
    // add freed block to free list after head
    header->size = *(size_t *)header & ~1L;
    // add freed block to free list after head
    header->next = free_list_head->next;
    header->prior = free_list_head;
    free_list_head->next = free_list_head->next->prior = header;
    // FIXME: coalesce! (requires adding footers, too)
}
