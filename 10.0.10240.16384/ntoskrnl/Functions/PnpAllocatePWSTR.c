// PnpAllocatePWSTR 
 
int __fastcall PnpAllocatePWSTR(unsigned __int16 *a1, unsigned int a2, int a3, int *a4)
{
  int v5; // r4
  int v8; // r0
  int v9[6]; // [sp+0h] [bp-18h] BYREF

  v9[0] = (int)a4;
  v5 = 0;
  *a4 = 0;
  if ( !a1 )
    return v5;
  v5 = RtlStringCchLengthW(a1, a2, v9);
  if ( v5 < 0 )
LABEL_10:
    JUMPOUT(0x7C6A26);
  if ( !v9[0] )
  {
LABEL_9:
    if ( v5 >= 0 )
      return v5;
    goto LABEL_10;
  }
  if ( RtlULongLongToULong(2 * (v9[0] + 1), (unsigned __int64)(unsigned int)(v9[0] + 1) >> 31, v9) < 0 )
    goto LABEL_10;
  v8 = ExAllocatePoolWithTag(1, v9[0], a3);
  *a4 = v8;
  if ( v8 )
  {
    v5 = RtlStringCbCopyW(v8, v9[0]);
    goto LABEL_9;
  }
  return sub_7C6A24();
}
