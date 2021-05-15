// MiCfgMarkValidEntries 
 
int __fastcall MiCfgMarkValidEntries(int a1, unsigned int a2, unsigned int a3, _DWORD *a4, unsigned int a5, _DWORD *a6, char a7)
{
  _DWORD *v7; // r6
  int v10; // r0
  unsigned int *v11; // r5
  unsigned int v12; // r2
  unsigned int v13; // t1
  unsigned int v14; // r1
  _DWORD *v15; // r2
  int v16; // r0
  int v17; // r4
  int v18; // r0
  int v19; // r5
  int v21; // [sp+8h] [bp-30h] BYREF
  _DWORD v22[10]; // [sp+10h] [bp-28h] BYREF

  v7 = a4;
  *a6 = 0;
  if ( (a3 & 0xFFF) != 0 || (a2 & 0xFFF) != 0 )
    return -1073741811;
  v10 = 1;
  if ( a5 > 1 )
  {
    v11 = a4 + 2;
    do
    {
      v12 = *(v11 - 2);
      v13 = *v11;
      v11 += 2;
      if ( v12 > v13 )
        return -1073741811;
    }
    while ( ++v10 < a5 );
  }
  if ( a4[2 * a5 - 2] >= a3 )
    return -1073741811;
  v14 = 0;
  if ( a5 )
  {
    v15 = a4;
    while ( (*v15 & 0xF) == 0 )
    {
      v16 = v15[1];
      if ( (v16 & 0xFFFFFFFC) != 0 )
        break;
      if ( (a7 & 1) != 0 && (v16 & 1) != 0 )
        return -1073741790;
      ++v14;
      v15 += 2;
      if ( v14 >= a5 )
        goto LABEL_15;
    }
    return -1073741811;
  }
LABEL_15:
  if ( !MiIsProcessCfgEnabled() )
    return -1073741755;
  v18 = MiObtainReferencedVad(a2, &v21);
  v19 = v18;
  if ( !v18 )
    return v21;
  if ( a2 + a3 - 1 <= ((*(_DWORD *)(v18 + 16) << 12) | 0xFFFu) )
  {
    v22[0] = a5;
    v22[1] = v7;
    v22[2] = a6;
    v17 = MiPopulateCfgBitMap(-1069538996, v22, a2, (a2 + a3 + 4094) & 0xFFFFF000, 1);
    if ( v17 >= 0 )
      v17 = 0;
  }
  else
  {
    v17 = -1073741811;
  }
  MiUnlockAndDereferenceVad(v19);
  return v17;
}
