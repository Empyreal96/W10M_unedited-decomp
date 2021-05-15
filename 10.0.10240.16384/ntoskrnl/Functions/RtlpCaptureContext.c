// RtlpCaptureContext 
 
int __fastcall RtlpCaptureContext(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // lr
  __int64 v6; // d8
  __int64 v7; // d9
  __int64 v8; // d10
  __int64 v9; // d11
  __int64 v10; // d12
  __int64 v11; // d13
  __int64 v12; // d14
  __int64 v13; // d15
  int v14; // r2
  int v15; // r12
  int v16; // r1
  __int64 v22; // t1

  *(_DWORD *)(a1 + 68) = __get_CPSR() | 0x20;
  *(_DWORD *)(a1 + 64) = v5;
  v14 = 0;
  *(_DWORD *)(a1 + 60) = 0;
  *(_DWORD *)(a1 + 72) = 0;
  v15 = a1 + 144;
  v16 = __mrc(15, 0, 1, 0, 2);
  if ( (v16 & 0xF00000) != 0 )
  {
    __asm { VMRS            R3, FPSCR }
    *(_DWORD *)(a1 + 72) = _R3;
    *(_QWORD *)v15 = v6;
    *(_QWORD *)(a1 + 152) = v7;
    *(_QWORD *)(a1 + 160) = v8;
    *(_QWORD *)(a1 + 168) = v9;
    *(_QWORD *)(a1 + 176) = v10;
    *(_QWORD *)(a1 + 184) = v11;
    *(_QWORD *)(a1 + 192) = v12;
    *(_QWORD *)(a1 + 200) = v13;
  }
  else
  {
    v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    _R3 = 8;
    if ( v16 && (v16 = *(_DWORD *)(v16 + 320)) != 0 )
    {
      *(_DWORD *)(a1 + 72) = 0;
      v16 += 80;
      do
      {
        --_R3;
        v22 = *(_QWORD *)v16;
        v16 += 8;
        v14 = v22;
        *(_QWORD *)v15 = v22;
        v15 += 8;
      }
      while ( _R3 );
    }
    else
    {
      do
      {
        --_R3;
        *(_DWORD *)v15 = 0;
        *(_DWORD *)(v15 + 4) = 0;
        v15 += 8;
      }
      while ( _R3 );
    }
  }
  return CcSaveNVContext(a1, v16, v14, _R3, a5);
}
