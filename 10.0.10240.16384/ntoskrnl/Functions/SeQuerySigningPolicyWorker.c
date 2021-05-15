// SeQuerySigningPolicyWorker 
 
int __fastcall SeQuerySigningPolicyWorker(int a1, unsigned __int16 *a2, int a3, int a4, char *a5, char *a6, _BYTE *a7)
{
  char v8; // r4
  int result; // r0
  char *v11; // r3
  char v12; // r2
  char v13; // r2
  unsigned __int8 v14; // r3
  unsigned int v15; // r2
  unsigned int v16; // r7
  unsigned int v17; // r0
  unsigned int v18; // r6
  unsigned __int16 *v19; // r5
  char v20; // r2
  char v21[8]; // [sp+10h] [bp-28h] BYREF
  int var20[13]; // [sp+18h] [bp-20h] BYREF
  int varg_r3; // [sp+4Ch] [bp+14h]

  var20[10] = a1;
  var20[11] = (int)a2;
  var20[12] = a3;
  varg_r3 = a4;
  v8 = a3;
  if ( SeSecurityAttributePresent(a1, (int)&PspPackagedAppClaim) )
    return sub_7D5AEC();
  if ( !a2
    || !dword_64A164
    || (v16 = *(_DWORD *)dword_64A164) == 0
    || (v17 = *a2, v17 < *(unsigned __int16 *)(dword_64A164 + 4))
    || v17 > *(unsigned __int16 *)(dword_64A164 + 6)
    || (v18 = 0, var20[1] = *((_DWORD *)a2 + 1) + 8, LOWORD(var20[0]) = v17 - 8, HIWORD(var20[0]) = a2[1] - 8, !v16) )
  {
LABEL_5:
    if ( (v8 & 1) != 0 )
    {
      v14 = varg_r3;
      if ( !(_BYTE)varg_r3 )
        v14 = 18;
      *a7 = v14;
      *a5 = *((_BYTE *)SeProtectedMapping + 2 * (v14 >> 4));
      *a6 = *((_BYTE *)SeProtectedMapping + 2 * ((unsigned __int8)*a7 >> 4) + 1);
      v15 = (unsigned __int8)SeILSigningPolicy;
      if ( (unsigned __int8)SeILSigningPolicy > (unsigned int)(unsigned __int8)*a5 )
      {
        *a5 = SeILSigningPolicy;
        v15 = (unsigned __int8)SeILSigningPolicy;
      }
      if ( v15 > (unsigned __int8)*a6 )
        *a6 = v15;
      return 0;
    }
    v11 = a5;
    *a5 = SeILSigningPolicy;
    goto LABEL_7;
  }
  v19 = (unsigned __int16 *)(dword_64A164 + 8);
  while ( !RtlEqualUnicodeString((unsigned __int16 *)var20, v19, 1) )
  {
    ++v18;
    v19 += 4;
    if ( v18 >= v16 )
      goto LABEL_5;
  }
  var20[0] = 0;
  result = SeQueryInformationToken(a1, 29, var20);
  if ( result < 0 )
    return result;
  if ( (v8 & 1) != 0 )
  {
    if ( var20[0] )
    {
      *a5 = 11;
      v20 = 6;
    }
    else
    {
      *a5 = 11;
      v20 = 8;
    }
    *a6 = v20;
    v13 = 33;
    goto LABEL_9;
  }
  if ( !var20[0] )
  {
    *a5 = 8;
    v11 = &SeILSigningPolicy;
LABEL_7:
    v12 = *v11;
LABEL_8:
    *a6 = v12;
    v13 = 0;
LABEL_9:
    *a7 = v13;
    return 0;
  }
  result = SepIsLockedDown(v21);
  if ( result >= 0 )
  {
    if ( !v21[0] )
      JUMPOUT(0x7D5B5A);
    *a5 = 8;
    v12 = 6;
    goto LABEL_8;
  }
  return result;
}
