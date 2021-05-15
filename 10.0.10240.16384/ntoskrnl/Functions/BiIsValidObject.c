// BiIsValidObject 
 
int __fastcall BiIsValidObject(_DWORD *a1, unsigned int a2)
{
  unsigned int v2; // r3
  int result; // r0
  int v4; // r2
  int v5; // r3

  if ( !a1 )
    goto LABEL_13;
  if ( !*a1 )
    goto LABEL_13;
  v2 = a1[1];
  if ( !(v2 >> 28) )
    goto LABEL_13;
  if ( v2 >> 28 != 1 )
    return sub_814688();
  v4 = v2 & 0xFFFFF;
  if ( (v2 & 0xFFFFF) == 0 )
    goto LABEL_13;
  v5 = (v2 >> 20) & 0xF;
  if ( !v5 )
    goto LABEL_13;
  if ( v5 != 1 )
    goto LABEL_12;
  if ( v4 != 1 )
    JUMPOUT(0x8146A6);
  if ( a2 && !memcmp(a2, (unsigned int)&GUID_FIRMWARE_BOOTMGR, 16) )
LABEL_12:
    result = 1;
  else
LABEL_13:
    result = 0;
  return result;
}
