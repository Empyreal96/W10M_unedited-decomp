// PfSnParsePrefetchParam 
 
int __fastcall PfSnParsePrefetchParam(unsigned __int16 *a1, unsigned int *a2)
{
  unsigned int v4; // r0
  unsigned int v5; // r2
  unsigned int v6; // r1
  int v7; // r0
  unsigned __int16 *v9; // r8
  unsigned int v10; // r4
  __int16 *i; // r5
  int v12; // r0
  __int16 v13; // t1
  unsigned int v14; // r0
  _WORD v15[4]; // [sp+Ch] [bp-48h] BYREF
  _BYTE v16[30]; // [sp+14h] [bp-40h] BYREF
  __int16 v17; // [sp+32h] [bp-22h] BYREF

  v4 = RtlInitUnicodeString((unsigned int)v15, L"/prefetch:");
  if ( *a1 )
  {
    v5 = *((_DWORD *)a1 + 1);
    if ( (v5 & 1) != 0 )
      ExRaiseDatatypeMisalignment(v4);
    v6 = v5 + *a1;
    if ( v6 > MmUserProbeAddress || v6 < v5 )
      *(_BYTE *)MmUserProbeAddress = 0;
  }
  v7 = PfSnFindString(a1, v15);
  if ( !v7 )
    return -1073741275;
  v9 = (unsigned __int16 *)(v15[0] + v7);
  v10 = *a1 + *((_DWORD *)a1 + 1);
  for ( i = (__int16 *)v16; (unsigned int)v9 < v10; ++i )
  {
    if ( i >= &v17 )
      break;
    v12 = *v9;
    if ( v12 == 32 )
      break;
    if ( !iswdigit(v12) )
      return -1073741811;
    v13 = *v9++;
    *i = v13;
  }
  *i = 0;
  v14 = wtol((int)v16);
  if ( v14 > 8 )
    return -1073741811;
  *a2 = v14;
  return 0;
}
