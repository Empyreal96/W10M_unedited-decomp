// PopGenerateScratchMdl 
 
_DWORD *__fastcall PopGenerateScratchMdl(int a1, unsigned int a2)
{
  int v2; // r7
  _DWORD *v3; // r6
  int v4; // r1
  unsigned int v5; // r8
  int v6; // r10
  __int64 v7; // r4
  unsigned __int64 v8; // r0
  __int64 v9; // r0
  __int64 v12; // [sp+1Ch] [bp-24h]

  v2 = *(_DWORD *)(a1 + 152);
  v3 = 0;
  LODWORD(v12) = ReadTimeStampCounter();
  HIDWORD(v12) = v4;
  v5 = 0;
  if ( *(_DWORD *)(v2 + 8) )
  {
    v6 = v2 + 16;
    while ( 1 )
    {
      v7 = *(_QWORD *)(v6 + 8);
      v8 = v7 << 12;
      if ( *(_DWORD *)(v6 + 36) == -268435455
        && (v7 + *(_QWORD *)(v6 + 24)) << 12 >= (unsigned __int64)(a2 << 12) + 0x1000000 )
      {
        if ( HIDWORD(v8) > 1 || !is_mul_ok(0x1000u, v7) && (_DWORD)v8 )
          goto LABEL_16;
        if ( v8 <= 0x1000000 )
          v8 = 0x1000000i64;
        if ( HIDWORD(v8) + ((_DWORD)v8 != 0) != 1 || -(int)v8 >= a2 << 12 )
        {
          v3 = (_DWORD *)MmAllocatePagesForMdlEx(v8, SHIDWORD(v8), 0, 1, 0, 0, a2 << 12, 1, 13);
          if ( v3 )
            break;
        }
      }
      ++v5;
      v6 += 40;
      if ( v5 >= *(_DWORD *)(v2 + 8) )
        goto LABEL_16;
    }
    *v3 = *(_DWORD *)(dword_61EC98 + 80);
    *(_DWORD *)(dword_61EC98 + 80) = v3;
    *(_QWORD *)(dword_61EC98 + 88) += a2;
  }
LABEL_16:
  LODWORD(v9) = ReadTimeStampCounter();
  qword_61EFB0 += v9 - v12;
  return v3;
}
