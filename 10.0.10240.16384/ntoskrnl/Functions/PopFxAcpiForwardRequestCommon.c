// PopFxAcpiForwardRequestCommon 
 
int __fastcall PopFxAcpiForwardRequestCommon(int a1, int a2)
{
  int v3[3]; // [sp+0h] [bp-10h] BYREF
  int v4; // [sp+Ch] [bp-4h]

  v3[1] = 0;
  v4 = 0;
  v3[0] = 1;
  v3[2] = a1;
  if ( a1 != 1 )
    return -1073741637;
  v4 = a2;
  return PopFxPlatformInterface(v3);
}
