// RtlpPopulateLanguageConfigList 
 
int __fastcall RtlpPopulateLanguageConfigList(int a1, int *a2, int a3)
{
  int v4; // r5
  int v5; // r0
  int v6; // r4
  int v8; // r0

  v4 = 0;
  if ( a1 && a2 && a3 )
  {
    v4 = *a2;
    v5 = ZwEnumerateValueKey();
    v6 = v5;
    if ( v5 >= 0 )
      return sub_817FDC();
    if ( v5 == -2147483622 )
      v6 = 0;
  }
  else
  {
    v6 = -1073741811;
  }
  if ( !v4 && v6 != -1073741811 )
  {
    v8 = RtlpMuiRegCreateLanguageConfigList(1);
    v4 = v8;
    if ( !v8 )
      v6 = -1073741801;
    *a2 = v8;
  }
  if ( v6 < 0 )
  {
    if ( v4 )
      *(_WORD *)(v4 + 4) = 0;
  }
  return v6;
}
