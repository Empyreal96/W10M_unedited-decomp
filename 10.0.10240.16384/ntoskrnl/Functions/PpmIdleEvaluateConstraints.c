// PpmIdleEvaluateConstraints 
 
int __fastcall PpmIdleEvaluateConstraints(int a1, _QWORD *a2, int a3, int a4)
{
  int v4; // r5
  __int64 v7; // r0
  int v8; // r7
  int v9; // r4
  char v10; // r3
  int v12; // [sp+0h] [bp-20h] BYREF
  int v13; // [sp+4h] [bp-1Ch]

  v12 = a3;
  v13 = a4;
  v4 = *(_DWORD *)(a1 + 2944);
  LODWORD(v7) = RtlGetInterruptTimePrecise(&v12);
  v8 = v13;
  *a2 = v7;
  v9 = v12;
  *(_DWORD *)(v4 + 128) = v12;
  *(_DWORD *)(v4 + 132) = v8;
  *(_DWORD *)(v4 + 136) = *(_DWORD *)(a1 + 2960);
  *(_DWORD *)(v4 + 140) = *(_DWORD *)(a1 + 2964);
  *(_BYTE *)(v4 + 170) = *(_BYTE *)(a1 + 3222);
  *(_BYTE *)(v4 + 168) = *(_BYTE *)(a1 + 2992);
  v10 = *(_BYTE *)(a1 + 2993);
  *(_BYTE *)(v4 + 171) = 1;
  *(_BYTE *)(v4 + 169) = v10;
  if ( !*(_DWORD *)(a1 + 3272) && !*(_BYTE *)(a1 + 17) )
  {
    *(_BYTE *)(v4 + 171) = 0;
    *(_WORD *)(v4 + 36) |= 0x40u;
  }
  if ( *(_BYTE *)(a1 + 17) && PoAllProcessorsDeepIdle(v7, HIDWORD(v7)) )
  {
    *(_BYTE *)(v4 + 172) = 1;
    *(_WORD *)(v4 + 36) |= 0x80u;
  }
  else
  {
    *(_BYTE *)(v4 + 172) = 0;
  }
  if ( *(_BYTE *)(v4 + 1) )
    return sub_54FE44();
  *(_DWORD *)(v4 + 160) = -1;
  return v9;
}
