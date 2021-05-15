// EtwpAddLogHeader 
 
int __fastcall EtwpAddLogHeader(int result)
{
  __int16 v1; // r2
  int v2; // [sp+20h] [bp-40h] BYREF
  char v3[4]; // [sp+30h] [bp-30h] BYREF

  v1 = *(_WORD *)(result + 100);
  v2 = 0;
  if ( *(_DWORD *)(result + 4) >= (unsigned int)(unsigned __int16)(*(_WORD *)(result + 92) + v1 + 276) + 104 )
  {
    if ( off_617B54(25, 12, v3, &v2) >= 0 )
      JUMPOUT(0x80A6F4);
    result = sub_80A6EC();
  }
  return result;
}
