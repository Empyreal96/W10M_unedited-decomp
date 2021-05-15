// sub_8097E8 
 
void sub_8097E8()
{
  int v0; // r4
  int v1; // r3

  v0 = 0;
  v1 = *(unsigned __int8 *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 734);
  if ( v1 != 49 && v1 != 97 )
    v0 = -1073741790;
  if ( v0 < 0 )
    JUMPOUT(0x786D5E);
  JUMPOUT(0x786D54);
}
