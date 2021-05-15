// MiAddMdlTracker 
 
int __fastcall MiAddMdlTracker(int result, int a2, int a3)
{
  _DWORD *v3; // r7
  int v4; // r5
  int v7; // r4
  _DWORD *v8; // r6
  _DWORD *v9; // r5
  int v10; // r2
  int v11; // r0
  _DWORD *v12; // r3
  char v13[8]; // [sp+8h] [bp-30h] BYREF
  char var28[44]; // [sp+10h] [bp-28h] BYREF
  int vars4; // [sp+3Ch] [bp+4h]

  v3 = (_DWORD *)result;
  v4 = *(_DWORD *)(result + 8);
  if ( !v4 )
    v4 = PsInitialSystemProcess;
  v7 = *(_DWORD *)(v4 + 424);
  if ( v7 && *(_DWORD *)(v7 + 12) )
  {
    result = ExAllocateFromNPagedLookasideList((int)&unk_634780);
    v8 = (_DWORD *)result;
    if ( result )
    {
      *(_DWORD *)(result + 12) = v3;
      *(_DWORD *)(result + 20) = a2;
      *(_DWORD *)(result + 16) = v3[4];
      *(_DWORD *)(result + 24) = v3[6];
      *(_DWORD *)(result + 28) = v3[5];
      *(_DWORD *)(result + 32) = v3[7];
      memset((_BYTE *)(result + 36), 0, 32);
      if ( !RtlCaptureStackBackTrace(0, 8u, (int)(v8 + 9), (int)v13) )
      {
        v8[10] = vars4;
        v8[9] = MiGetInstructionPointer();
      }
      v8[17] = a3;
      v8[18] = v4;
      KeAcquireInStackQueuedSpinLock((unsigned int *)(v7 + 8), (unsigned int)var28);
      v9 = *(_DWORD **)v7;
      v10 = 0;
      if ( *(_DWORD *)v7 )
      {
        while ( 1 )
        {
          v11 = MiLockTrackerCompare(v3, v9, v10);
          if ( v11 <= 0 )
          {
            if ( v11 >= 0 )
              KeBugCheckEx(217, 1, (int)v9, (int)v3, *(_DWORD *)(v7 + 4));
            v12 = (_DWORD *)*v9;
            if ( !*v9 )
            {
              v10 = 0;
              break;
            }
          }
          else
          {
            v12 = (_DWORD *)v9[1];
            if ( !v12 )
            {
              v10 = 1;
              break;
            }
          }
          v9 = v12;
        }
      }
      RtlAvlInsertNodeEx(v7, (int)v9, v10, v8);
      *(_DWORD *)(v7 + 4) += a2;
      result = KeReleaseInStackQueuedSpinLock((int)var28);
    }
    else
    {
      *(_DWORD *)(v7 + 12) = 0;
    }
  }
  return result;
}
