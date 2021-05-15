// sub_528D08 
 
void sub_528D08(int a1, int a2, int a3, unsigned int a4, ...)
{
  _DWORD *v4; // r4
  unsigned int v5; // r2
  int v6; // r7
  _DWORD *v7; // r5
  int v8; // r2
  _DWORD *v9; // r3
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  if ( (a4 & 0x10) != 0 )
    v5 = a4 >> 13;
  else
    v5 = 0;
  v6 = *(_DWORD *)&MiSystemPartition[2 * ((a4 >> 2) & 1) + 1800];
  v4[47] = v6;
  v4[48] = v5;
  KeAcquireInStackQueuedSpinLock((unsigned int *)(v6 + 116), (unsigned int)va);
  v7 = *(_DWORD **)(v6 + 124);
  v8 = 0;
  if ( v7 )
  {
    while ( 1 )
    {
      if ( MiPagefileCompareOffset(v4 + 49, v7, v8) < 0 )
      {
        v9 = (_DWORD *)*v7;
        if ( !*v7 )
        {
          v8 = 0;
          break;
        }
      }
      else
      {
        v9 = (_DWORD *)v7[1];
        if ( !v9 )
        {
          v8 = 1;
          break;
        }
      }
      v7 = v9;
    }
  }
  RtlAvlInsertNodeEx(v6 + 124, (int)v7, v8, v4 + 49);
  KeReleaseInStackQueuedSpinLock((int)va);
  JUMPOUT(0x4DF178);
}
