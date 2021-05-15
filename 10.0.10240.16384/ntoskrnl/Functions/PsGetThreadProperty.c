// PsGetThreadProperty 
 
int __fastcall PsGetThreadProperty(int a1, int a2, int a3)
{
  char v3; // r5
  int v6; // r0
  int v8[4]; // [sp+0h] [bp-10h] BYREF

  v8[0] = 0;
  v3 = a3;
  if ( (a3 & 0xFFFFFFFE) != 0 || PspValidateThread() < 0 )
    return 0;
  if ( PspGetProperty(a1 + 1060, a2, v8) < 0 && (v3 & 1) == 0 )
  {
    v6 = *(_DWORD *)(*(_DWORD *)(a1 + 336) + 288);
    __dmb(0xBu);
    if ( v6 )
      return PsGetJobProperty(v6, a2);
  }
  return v8[0];
}
