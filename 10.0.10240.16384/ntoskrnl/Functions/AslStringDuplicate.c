// AslStringDuplicate 
 
int __fastcall AslStringDuplicate(unsigned int *a1, unsigned __int16 *a2, int a3, int a4)
{
  int v6; // r4
  unsigned int v7; // r6
  int v8; // r0
  int v9; // r2
  _WORD *v10; // r0
  unsigned int v11; // r5
  int v13[6]; // [sp+8h] [bp-18h] BYREF

  v13[0] = a4;
  *a1 = 0;
  if ( !a2 )
    return 0;
  v6 = RtlStringCchLengthW(a2, 0x7FFFFFFFu, v13);
  if ( v6 < 0 )
  {
    AslLogCallPrintf(1, (int)"AslStringDuplicate", 465, "RtlStringCchLengthW failed [%x]", v6);
    return v6;
  }
  v7 = v13[0] + 1;
  if ( (unsigned int)(v13[0] + 1) < v13[0] )
  {
    v6 = -1073741675;
    v9 = 476;
    goto LABEL_16;
  }
  v8 = RtlULongLongToULong(2 * v7, (unsigned __int64)v7 >> 31, v13);
  v6 = v8;
  if ( v8 < 0 )
  {
    v9 = 482;
LABEL_16:
    AslLogCallPrintf(1, (int)"AslStringDuplicate", v9, "SIZE_T arithmetic failed [%x]", v6);
    return v6;
  }
  v10 = AslAlloc(v8, v13[0]);
  v11 = (unsigned int)v10;
  if ( v10 )
  {
    v6 = RtlStringCchCopyW(v10, v7, (int)a2);
    if ( v6 >= 0 )
    {
      *a1 = v11;
      v11 = 0;
      v6 = 0;
    }
    else
    {
      AslLogCallPrintf(1, (int)"AslStringDuplicate", 499, "RtlStringCchCopyW failed [%x]", v6);
    }
    if ( v11 )
      ExFreePoolWithTag(v11);
  }
  else
  {
    v6 = -1073741801;
    AslLogCallPrintf(1, (int)"AslStringDuplicate", 489, "Out of memory");
  }
  return v6;
}
