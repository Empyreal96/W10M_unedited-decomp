// CcAdjustThrottle 
 
int __fastcall CcAdjustThrottle(unsigned int *a1, __int64 *a2, int a3)
{
  __int64 v3; // kr00_8
  unsigned int v5; // r1
  __int64 v6; // r4
  unsigned int v7; // r2
  int v8; // r9
  unsigned int v9; // r2
  unsigned int v11; // r1
  unsigned int v12; // r1
  unsigned int v13; // [sp+0h] [bp-20h]

  v3 = a2[1];
  v13 = a1[1];
  v5 = *a1;
  v6 = *a2;
  v7 = a1[2] - a3;
  v8 = 0;
  if ( CcPagesSkippedDueToHotSpot )
  {
    if ( v7 <= (unsigned __int64)CcPagesSkippedDueToHotSpot )
      v7 = 0;
    else
      v7 -= CcPagesSkippedDueToHotSpot;
    CcPagesSkippedDueToHotSpot = 0i64;
  }
  if ( v7 < 0x200 )
  {
    v7 = 512;
    v8 = 1;
  }
  v9 = v7 >> 2;
  if ( v9 > (unsigned int)v6 )
    v9 = v6;
  if ( v5 >= HIDWORD(v3) + ((unsigned int)(3 * (v6 - HIDWORD(v3))) >> 2) )
    return sub_54AB84();
  if ( HIDWORD(v6) < (unsigned int)v6 )
  {
    v12 = v6 - HIDWORD(v6);
    if ( v8 )
    {
      if ( v12 >> 2 > 0x5000 )
        v12 >>= 2;
    }
    else if ( (unsigned int)v6 - v9 >= HIDWORD(v6) )
    {
      v12 = v9;
    }
    LODWORD(v6) = v6 - v12;
    goto LABEL_14;
  }
  if ( v5 < (unsigned int)v6 - v9 && v13 <= (unsigned int)v6 )
  {
    v11 = ((unsigned int)v6 - v5) >> 3;
    if ( v11 <= v9 )
    {
      if ( HIDWORD(v6) - (int)v6 > v9 )
      {
        LODWORD(v6) = v6 + v9;
        goto LABEL_14;
      }
    }
    else if ( HIDWORD(v6) - (int)v6 > v11 )
    {
      LODWORD(v6) = v6 + v11;
      goto LABEL_14;
    }
    LODWORD(v6) = HIDWORD(v6);
  }
LABEL_14:
  *((_DWORD *)a2 + 3) = ((unsigned int)v6 >> 1) + ((unsigned int)v6 >> 2);
  *(_DWORD *)a2 = v6;
  return CcAdjustTopBottomThresholds(a2);
}
