// RtlpCaptureContext 
 
int __fastcall RtlpCaptureContext(int a1)
{
  int v1; // lr
  __int64 v2; // d8
  __int64 v3; // d9
  __int64 v4; // d10
  __int64 v5; // d11
  __int64 v6; // d12
  __int64 v7; // d13
  __int64 v8; // d14
  __int64 v9; // d15
  int v10; // r12
  unsigned int v16; // r1
  int v17; // r3
  int v18; // r1
  __int64 *v19; // r1
  __int64 v20; // t1

  *(_DWORD *)(a1 + 68) = __get_CPSR() | 0x20;
  *(_DWORD *)(a1 + 64) = v1;
  *(_DWORD *)(a1 + 60) = 0;
  *(_DWORD *)(a1 + 72) = 0;
  v10 = a1 + 144;
  if ( (__mrc(15, 0, 1, 0, 2) & 0xF00000) != 0 )
  {
    __asm { VMRS            R3, FPSCR }
    *(_DWORD *)(a1 + 72) = _R3;
    *(_QWORD *)v10 = v2;
    *(_QWORD *)(a1 + 152) = v3;
    *(_QWORD *)(a1 + 160) = v4;
    *(_QWORD *)(a1 + 168) = v5;
    *(_QWORD *)(a1 + 176) = v6;
    *(_QWORD *)(a1 + 184) = v7;
    *(_QWORD *)(a1 + 192) = v8;
    *(_QWORD *)(a1 + 200) = v9;
  }
  else
  {
    v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v17 = 8;
    if ( v16 && (v18 = *(_DWORD *)(v16 + 320)) != 0 )
    {
      *(_DWORD *)(a1 + 72) = 0;
      v19 = (__int64 *)(v18 + 80);
      do
      {
        --v17;
        v20 = *v19++;
        *(_QWORD *)v10 = v20;
        v10 += 8;
      }
      while ( v17 );
    }
    else
    {
      do
      {
        --v17;
        *(_DWORD *)v10 = 0;
        *(_DWORD *)(v10 + 4) = 0;
        v10 += 8;
      }
      while ( v17 );
    }
  }
  return CcSaveNVContext();
}
