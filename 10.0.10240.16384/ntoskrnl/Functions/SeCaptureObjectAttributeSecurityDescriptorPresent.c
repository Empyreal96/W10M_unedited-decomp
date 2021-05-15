// SeCaptureObjectAttributeSecurityDescriptorPresent 
 
int __fastcall SeCaptureObjectAttributeSecurityDescriptorPresent(int a1, char a2, _BYTE *a3)
{
  int v3; // r3

  *a3 = 0;
  if ( a2 )
  {
    if ( a1 )
    {
      if ( (a1 & 3) != 0 )
        ExRaiseDatatypeMisalignment(a1);
      v3 = *(_DWORD *)(a1 + 16);
      __dmb(0xBu);
      if ( v3 )
        *a3 = 1;
    }
  }
  else if ( a1 && *(_DWORD *)(a1 + 16) )
  {
    *a3 = 1;
  }
  return 0;
}
