// IopGetDriverNameFromKeyNode 
 
int __fastcall IopGetDriverNameFromKeyNode(int a1)
{
  int v3; // r3
  const __int16 *v4; // [sp+10h] [bp-28h] BYREF

  if ( IopGetRegistryValue(a1, L"ObjectName", 30, &v4) >= 0 )
    return sub_7CB200();
  if ( IopGetRegistryValue(a1, L"Type", 0, &v4) >= 0 )
  {
    if ( *((_DWORD *)v4 + 3) )
    {
      v3 = *(_DWORD *)((char *)v4 + *((_DWORD *)v4 + 2));
      v4 = L"\\Driver\\";
      if ( v3 == 2 || v3 == 8 )
        v4 = L"\\FileSystem\\";
      JUMPOUT(0x7CB23C);
    }
    ExFreePoolWithTag((unsigned int)v4);
  }
  return -1073741472;
}
