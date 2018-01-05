/*
 * Copyright (c) 2009, Lawrence Livermore National Security, LLC.
 * Produced at the Lawrence Livermore National Laboratory.
 * Written by Adam Moody <moody20@llnl.gov>.
 * LLNL-CODE-411039.
 * All rights reserved.
 * This file was originally part of The Scalable Checkpoint / Restart (SCR) library.
 * For details, see https://github.com/llnl/scr.git
 * Please also read this file: LICENSE.TXT.
*/

#ifndef AXL_H
#define AXL_H

#include "fu_filemap.h"

/* do a synchronous flush operation */
int axl_flush_sync(fu_filemap* map, int id);

/* stop all ongoing asynchronous flush operations */
int axl_flush_async_stop(void);

/* start an asynchronous flush from cache to parallel file system under SCR_PREFIX */
int axl_flush_async_start(fu_filemap* map, int id);

/* check whether the flush from cache to parallel file system has completed */
int axl_flush_async_test(fu_filemap* map, int id, double* bytes);

/* complete the flush from cache to parallel file system */
int axl_flush_async_complete(fu_filemap* map, int id);

/* wait until the checkpoint currently being flushed completes */
int axl_flush_async_wait(fu_filemap* map);

/* initialize the async transfer processes */
int axl_flush_async_init(void);

/* finalize the async transfer processes */
int axl_flush_async_finalize(void);

#endif // AXL_H
