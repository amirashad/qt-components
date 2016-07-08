/* 
 * File:   qcomps_global.h
 * Author: Rashad Amirjanov
 *
 * Created on May 3, 2012, 11:48 PM
 */

#ifndef QCOMPS_GLOBAL_H
#define	QCOMPS_GLOBAL_H

#ifdef QCOMPS_DLL
#define QCOMPS_EXPORT Q_DECL_EXPORT
#else
#define QCOMPS_EXPORT Q_DECL_IMPORT
#endif

#ifndef WIN32
#undef QCOMPS_EXPORT
#define QCOMPS_EXPORT 
#endif

#endif	/* QCOMPS_GLOBAL_H */

