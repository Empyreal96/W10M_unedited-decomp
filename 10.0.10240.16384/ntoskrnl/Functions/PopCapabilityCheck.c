// PopCapabilityCheck 
 
int __fastcall PopCapabilityCheck(int a1, int a2)
{
  int v2; // r4
  int v4; // [sp+0h] [bp-18h] BYREF
  int v5; // [sp+4h] [bp-14h] BYREF
  __int16 v6; // [sp+8h] [bp-10h] BYREF
  __int16 v7; // [sp+Ah] [bp-Eh]
  const __int16 *v8; // [sp+Ch] [bp-Ch]

  v4 = a1;
  v5 = a2;
  LOBYTE(v4) = 0;
  v2 = 0;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  if ( sub_455E68(L"ID_CAP_SCREENOFF", a2, &v5) >= 0 )
  {
    v6 = 2 * v5;
    v7 = 2 * v5 + 2;
    v8 = L"ID_CAP_SCREENOFF";
    if ( RtlCapabilityCheck(0, &v6, &v4) >= 0 )
      v2 = (unsigned __int8)v4;
  }
  return v2;
}
