// RtlAddProcessTrustLabelAce 
 
int __fastcall RtlAddProcessTrustLabelAce(unsigned __int8 *a1, unsigned int a2, int a3, _BYTE *a4, char a5, int a6)
{
  unsigned int v10; // r5
  int v11; // r1
  int v12; // r0
  __int16 v13; // r3
  int v15[8]; // [sp+0h] [bp-20h] BYREF

  v15[0] = a3;
  v15[1] = (int)a4;
  if ( !a1 || !RtlValidAcl(a1) )
    return -1073741705;
  if ( a5 != 20 )
    return -1073741811;
  if ( !RtlValidSid(a4) )
    return -1073741704;
  if ( !RtlIsValidProcessTrustLabelSid((int)a4) )
    return -1073741811;
  v10 = *a1;
  if ( v10 > 4 || a2 > 4 )
    return -1073741735;
  if ( v10 <= a2 )
    LOBYTE(v10) = a2;
  if ( (a3 & 0xFFFFFFE0) != 0 || (a6 & 0xFF000000) != 0 )
    return -1073741811;
  if ( !RtlFirstFreeAce((int)a1, v15) )
    return -1073741705;
  v11 = v15[0];
  v12 = 4 * ((unsigned __int8)a4[1] + 4);
  if ( !v15[0] || v12 + v15[0] > (unsigned int)&a1[*((unsigned __int16 *)a1 + 1)] )
    return -1073741671;
  *(_BYTE *)(v15[0] + 1) = a3;
  *(_BYTE *)v11 = 20;
  *(_WORD *)(v11 + 2) = v12;
  *(_DWORD *)(v11 + 4) = a6;
  RtlCopySid(4 * ((unsigned __int8)a4[1] + 2), v11 + 8, (int)a4);
  v13 = *((_WORD *)a1 + 2);
  *a1 = v10;
  *((_WORD *)a1 + 2) = v13 + 1;
  return 0;
}
