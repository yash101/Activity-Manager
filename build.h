/*
 * build.h
 *
 *  Created on: Dec 12, 2015
 *      Author: yash
 */

#ifndef BUILD_H_
#define BUILD_H_

#ifndef CONFIG_FS_ENCRYPTION_KEY
#warning "The database will be stored unencrypted! Please set CONFIG_FS_ENCRYPTION_KEY as a compilation variable or in /build.h"
#define CONFIG_FS_ENCRYPTION_KEY '\0'
#endif

#endif /* BUILD_H_ */
