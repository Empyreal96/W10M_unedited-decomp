// PnpConcatPWSTR 
 
int __fastcall PnpConcatPWSTR(unsigned int a1, int a2, unsigned int *a3, unsigned int a4, int a5, int a6)
{
  unsigned int v9; // r5
  int v10; // r9
  unsigned int v11; // r6
  unsigned __int16 **v13; // r4
  int v14; // r4
  _WORD *v16; // r0
  int v17; // r6
  int v18; // r5
  int *v19; // r3
  unsigned int v20; // [sp+0h] [bp-28h] BYREF
  int var24[15]; // [sp+4h] [bp-24h] BYREF

  var24[11] = a1;
  var24[12] = a2;
  var24[13] = (int)a3;
  var24[0] = (int)a3;
  var24[1] = a4;
  var24[14] = a4;
  v9 = 1;
  v10 = (int)&a5;
  v11 = 0;
  v20 = 0;
  for ( *a3 = 0; v11 < a4; ++v11 )
  {
    v13 = (unsigned __int16 **)((-v10 & 3) + v10);
    v10 = (int)(v13 + 1);
    if ( *v13 )
    {
      v14 = RtlStringCchLengthW(*v13, a1, var24);
      if ( v14 < 0 )
        goto LABEL_17;
      v9 += var24[0];
    }
  }
  if ( v9 > a1 )
    return sub_7C9128();
  v14 = RtlULongLongToULong(2 * v9, (unsigned __int64)v9 >> 31, &v20);
  if ( v14 < 0 )
    goto LABEL_17;
  v16 = (_WORD *)ExAllocatePoolWithTag(1, v20, a2);
  *a3 = (unsigned int)v16;
  if ( !v16 )
  {
    v14 = -1073741670;
LABEL_17:
    if ( *a3 )
    {
      ExFreePoolWithTag(*a3);
      *a3 = 0;
    }
    return v14;
  }
  v17 = (int)&a5;
  v18 = 0;
  *v16 = 0;
  if ( a4 )
  {
    while ( 1 )
    {
      v19 = (int *)((-v17 & 3) + v17);
      v17 = (int)(v19 + 1);
      if ( *v19 )
      {
        v14 = RtlStringCbCatW((unsigned __int16 *)*a3, v20, *v19, (int)v19);
        if ( v14 < 0 )
          break;
      }
      if ( ++v18 >= a4 )
        return v14;
    }
    goto LABEL_17;
  }
  return v14;
}
