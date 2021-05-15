// PfTAllocateBuffers 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PfTAllocateBuffers(int a1, int a2, unsigned int a3, int a4)
{
  unsigned int v8; // r8
  _BYTE *v9; // r0
  _DWORD *v10; // r5
  _QWORD *v11; // r0
  _DWORD *v12; // r2 OVERLAPPED
  int v13; // r1 OVERLAPPED
  int result; // r0

  *(_DWORD *)a1 = *(_DWORD *)a1 & 0xF | (16 * a2);
  v8 = 0;
  if ( a3 )
  {
    while ( 1 )
    {
      v9 = (_BYTE *)ExAllocatePoolWithTag(1, a2, a4);
      v10 = v9;
      if ( !v9 )
        break;
      if ( (*(_DWORD *)a1 & 0xF) != 0 )
      {
        memset(v9, 0, a2);
        *v10 = v10;
        v10[1] = v10;
        v10[6] = 2048;
      }
      else
      {
        PfTLbInitialize();
      }
      ++v8;
      *v10 = *(_DWORD *)(a1 + 12);
      *(_DWORD *)(a1 + 12) = v10;
      ++*(_WORD *)(a1 + 10);
      ++*(_DWORD *)(a1 + 4);
      if ( v8 >= a3 )
        goto LABEL_7;
    }
    result = -1073741670;
  }
  else
  {
LABEL_7:
    v11 = (_QWORD *)PfTGetFreeBuffer(a1);
    v12 = (_DWORD *)(a1 + 16);
    v13 = *(_DWORD *)(a1 + 16);
    *v11 = *(_QWORD *)&v13;
    if ( *(_DWORD *)(v13 + 4) != a1 + 16 )
      __fastfail(3u);
    *(_DWORD *)(v13 + 4) = v11;
    *v12 = v11;
    result = 0;
  }
  return result;
}
