// SepRmFetchGlobalSacl 
 
int __fastcall SepRmFetchGlobalSacl(unsigned __int16 *a1)
{
  unsigned int v2; // r4
  int v3; // r0
  unsigned __int16 *v4; // r5
  int v5; // r4
  int v7[7]; // [sp+Ch] [bp-1Ch] BYREF

  v2 = *a1 + 98;
  v7[0] = 0;
  v3 = ExAllocatePoolWithTag(1, v2, 1818448711);
  v4 = (unsigned __int16 *)v3;
  if ( v3 )
  {
    if ( RtlStringCbCopyW(v3, v2) >= 0 )
      RtlStringCchCatNW(v4, v2 >> 1, *((_DWORD *)a1 + 1), *a1 >> 1);
    v5 = SepRegOpenKey(v4, 513, v7);
    if ( v5 >= 0 )
      return sub_8169F4();
  }
  else
  {
    v5 = -1073741801;
  }
  if ( v7[0] )
  {
    ZwClose();
    v7[0] = 0;
  }
  if ( v4 )
    ExFreePoolWithTag((unsigned int)v4);
  return v5;
}
