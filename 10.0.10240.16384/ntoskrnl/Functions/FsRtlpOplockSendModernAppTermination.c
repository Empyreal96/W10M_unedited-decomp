// FsRtlpOplockSendModernAppTermination 
 
int __fastcall FsRtlpOplockSendModernAppTermination(int a1, int a2, int a3, int a4)
{
  int v4; // r7
  int v6; // r3
  int *v7; // r4
  unsigned int v8; // r5
  int *v9; // r0
  _DWORD *v10; // r1
  _DWORD *v11; // r6
  _DWORD *v12; // t1
  unsigned int v13; // r2
  _DWORD *v14; // r0
  int v15; // r3
  int result; // r0
  int v17; // [sp+0h] [bp-18h] BYREF
  int v18; // [sp+4h] [bp-14h]

  v17 = a3;
  v18 = a4;
  v4 = 0;
  if ( a2 || (v6 = *(_DWORD *)(a1 + 8)) == 0 )
  {
    v8 = 4096;
    v9 = (int *)ExAllocatePoolWithTag(1, 4096);
    v7 = v9;
    if ( v9 )
    {
      memset(v9, 0, 4096);
      v12 = *(_DWORD **)(a1 + 36);
      v11 = (_DWORD *)(a1 + 36);
      v10 = v12;
      v4 = 1;
      v13 = 1;
      if ( v12 == v11 )
      {
LABEL_10:
        v15 = v13 - 1;
      }
      else
      {
        v14 = v7 + 1;
        while ( v13 < 0x400 )
        {
          ++v13;
          *v14++ = *(_DWORD *)(v10[4] + 176);
          v10 = (_DWORD *)*v10;
          if ( v10 == v11 )
            goto LABEL_10;
        }
        memset(v7, 0, 4096);
        v15 = -1;
        v8 = 4;
      }
      *v7 = v15;
    }
    else
    {
      v17 = -1;
      v7 = &v17;
      v18 = 0;
      v8 = 4;
    }
  }
  else
  {
    v17 = 1;
    v7 = &v17;
    v8 = 8;
    v18 = *(_DWORD *)(v6 + 176);
  }
  result = FsRtlSendModernAppTermination((int)v7, v8, 1);
  if ( v4 )
    result = ExFreePoolWithTag(v7);
  return result;
}
