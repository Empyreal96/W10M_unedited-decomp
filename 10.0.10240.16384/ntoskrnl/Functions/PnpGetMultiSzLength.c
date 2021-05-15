// PnpGetMultiSzLength 
 
int __fastcall PnpGetMultiSzLength(int a1, int a2, unsigned int *a3, int a4)
{
  int result; // r0
  int v8; // r5
  unsigned int v9; // r2
  int v10[6]; // [sp+0h] [bp-18h] BYREF

  v10[0] = (int)a3;
  v10[1] = a4;
  *a3 = 0;
  do
  {
    result = RtlStringCchLengthW((unsigned __int16 *)(a1 + 2 * *a3), a2 - *a3, v10);
    if ( result < 0 )
      break;
    v8 = v10[0];
    v9 = *a3 + v10[0];
    if ( v9 < *a3 )
      return sub_7E0BB8();
    *a3 = v9;
    if ( v9 + 1 < v9 )
      return sub_7E0BB8();
    result = 0;
    *a3 = v9 + 1;
  }
  while ( v8 );
  return result;
}
