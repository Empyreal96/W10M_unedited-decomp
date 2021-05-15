// EtwpEnableDisableSpecialGuids 
 
int __fastcall EtwpEnableDisableSpecialGuids(unsigned int a1, int a2, int a3, int a4, int a5, _BYTE *a6)
{
  unsigned int v6; // r1
  unsigned int v8; // r7
  unsigned int *v9; // r3
  unsigned int *v11; // [sp+4h] [bp-24h]

  v6 = a1;
  *a6 = 1;
  if ( a3 == 2 )
    return sub_808008();
  if ( a3 == 1 || !a3 )
  {
    v8 = 0;
    v9 = (unsigned int *)&EtwpUmglProviders;
    do
    {
      v11 = v9 + 2;
      if ( !memcmp(*v9, v6, 16) )
        JUMPOUT(0x808080);
      ++v8;
      v6 = a1;
      v9 = v11;
    }
    while ( v8 < 0xA );
    if ( !memcmp((unsigned int)KernelRundownGuid, a1, 16) )
      JUMPOUT(0x808034);
  }
  *a6 = 0;
  return -1073741275;
}
