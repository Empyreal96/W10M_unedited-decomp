// SdbpMatchDeviceString 
 
int __fastcall SdbpMatchDeviceString(int a1, unsigned __int16 *a2, int a3, int a4)
{
  int v6; // r5
  int v7; // r0
  int v8; // r2
  int v9; // r3
  int v10; // r0

  v6 = 0;
  v7 = SdbFindFirstTag(a1, a3, a4);
  if ( !v7 || (v10 = SdbGetStringTagPtr(a1, v7, v8, v9)) != 0 && a2 && !wcsicmp(v10, a2) )
    v6 = 1;
  return v6;
}
