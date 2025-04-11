/*******************************************************************************
** Copyright 2025-present HMS Industrial Networks AB.
** Licensed under the MIT License.
********************************************************************************
** File Description:
** Platform dependent macros and functions required by the ABCC driver and
** Anybus objects implementation to be platform independent.
********************************************************************************
*/

#include "abcc_software_port.h"
#include "process.h"
#include "windows.h"

static HANDLE ghMutex = NULL;


void ABCC_PORT_UseCriticalImpl( void )
{
   if( ghMutex == NULL )
   {
      ghMutex = CreateMutex( NULL,       /* Default security attributes.  */
                          FALSE,      /* Initially not owned.          */
                          NULL );
   }
}

void ABCC_PORT_EnterCriticalImpl( void )
{
   WaitForSingleObject(
            ghMutex,    /* Handle to the mutex. */
            INFINITE);  /* No time-out interval. */
}

void ABCC_PORT_ExitCriticalImpl( void )
{
   ReleaseMutex(ghMutex);
}
