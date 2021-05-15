// FsRtlpOplockBreakToNone 
 
int __fastcall FsRtlpOplockBreakToNone(_DWORD *a1, int a2, int a3, int a4, int a5, int a6, int a7, _BYTE *a8, int a9)
{
  int result; // r0
  int v13; // r0
  int v14; // r4
  unsigned int *v15; // r2
  unsigned int v16; // r1
  _DWORD *i; // r4
  int v19; // r3
  int v20; // r3
  int v23; // [sp+18h] [bp-30h] BYREF

  result = 0;
  if ( a1 )
  {
    v13 = a1[18];
    if ( v13 != 1 && (v13 & 0x6000) == 0 )
    {
      if ( (v13 & 0x1F00F90) != 0 )
      {
        if ( (v13 & 0x1F0FFDF) != 16 && (v13 & 0x1F0FFDF) != 4112 )
        {
          if ( (v13 & 0x100) != 0 )
          {
            if ( (a4 & 0x10010000) != 0 )
              return -1073739511;
            a1[18] = v13 & 0xFFFFFEFF;
            a1[18] = v13 & 0xFFFFFEFF | 0x400;
          }
          else if ( (v13 & 0x80) != 0 )
          {
            if ( (a4 & 0x10010000) == 0 )
            {
              a1[18] = a1[18] & 0x20 | 1;
              a1[1] = 0;
              if ( a1[3] )
              {
                FsRtlpClearOwnerThread((int)a1, 0);
                *((_BYTE *)a1 + 16) = 0;
              }
              return 0;
            }
            return -1073739511;
          }
          goto LABEL_25;
        }
        if ( (a4 & 0x10010000) != 0 )
          return -1073739511;
        for ( i = (_DWORD *)a1[5]; i != a1 + 5; i = (_DWORD *)*i )
        {
          if ( *(_DWORD *)(i[2] + 16) != 590400 )
          {
            i = (_DWORD *)i[1];
            FsRtlpRemoveAndCompleteReadOnlyIrp(*i, 0, 0);
          }
        }
        v19 = a1[18] & 0x20;
        if ( (a1[18] & 0x1F0FFDF) == 4112 )
          v20 = v19 | 0x1000;
        else
          v20 = v19 | 1;
        a1[18] = v20;
      }
      else
      {
        v14 = *a1;
        if ( (v13 & 0x1000) == 0 )
        {
          if ( (a4 & 0x10010000) != 0 )
            return -1073739511;
          *(_BYTE *)(v14 + 37) = KeAcquireQueuedSpinLock(7);
          __dmb(0xBu);
          v15 = (unsigned int *)(v14 + 56);
          do
            v16 = __ldrex(v15);
          while ( __strex(0, v15) );
          __dmb(0xBu);
          KeReleaseQueuedSpinLock(7, *(unsigned __int8 *)(v14 + 37));
          if ( *(_BYTE *)(v14 + 36) )
          {
            *(_DWORD *)(v14 + 28) = 8;
            FsRtlpModifyThreadPriorities(a1, 0, 0);
            FsRtlpClearOwnerThread((int)a1, 0);
            *((_BYTE *)a1 + 16) = 0;
            *(_DWORD *)(*a1 + 24) = -1073741536;
            pIofCompleteRequest(*a1, 1);
            *a1 = 0;
            ObfDereferenceObjectWithTag(a1[1]);
            a1[1] = 0;
            a1[18] = a1[18] & 0x20 | 1;
            while ( (_DWORD *)a1[11] != a1 + 11 )
              FsRtlpRemoveAndCompleteWaitingIrp(a1[11]);
            return 0;
          }
          *(_DWORD *)(*a1 + 28) = 8;
          *(_DWORD *)(*a1 + 24) = 0;
          pIofCompleteRequest(*a1, 1);
          *a1 = 0;
          a1[18] |= 0x200u;
LABEL_25:
          if ( (a4 & 8) == 0 && FsRtlpOplockKeysEqual(*(_DWORD *)(a2 + 28), a1[1], 0) )
            return 0;
          if ( (a4 & 1) != 0 )
            return 264;
          if ( (a4 & 0x10010000) == 0 )
          {
            FsRtlpModifyThreadPriorities(a1, 0, 1);
            FsRtlpOplockSendModernAppTermination(a1, 0);
            *a8 = 0;
            return FsRtlpWaitOnIrp(a1, a3, a5, a6, a7, &v23, 0, a9, 0);
          }
          return -1073739511;
        }
      }
    }
    return 0;
  }
  return result;
}
