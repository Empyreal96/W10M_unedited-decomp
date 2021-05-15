// IoSetMasterIrpStatus 
 
int __fastcall IoSetMasterIrpStatus(int result, int a2)
{
  int v2; // r4

  v2 = *(_DWORD *)(result + 24);
  if ( a2 == -2147483626
    || v2 != -2147483626 && (v2 == 1073741877 || a2 != 1073741877 && (a2 & 0xC0000000) > (v2 & 0xC0000000)) )
  {
    result = sub_5204A4();
  }
  return result;
}
