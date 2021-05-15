// sub_7E06BC 
 
void sub_7E06BC()
{
  int v0; // r6
  _DWORD **v1; // r8
  _DWORD *v2; // r5
  int v3; // r0
  _DWORD *v4; // r0
  int v5; // r7

  v2 = *v1;
  while ( v2 != v1 )
  {
    v3 = (int)(v2 - 13);
    v2 = (_DWORD *)*v2;
    v4 = PiSwFindPdoAssociation(v3, v0, 1);
    if ( v4 )
    {
      v5 = v4[3];
      if ( (*(_DWORD *)(*(_DWORD *)(v5 + 40) + 4) & 0x20) == 0 )
        PiSwProcessRemove(v4[3], 0);
      PiSwDestroyDeviceObject(v5);
    }
  }
  JUMPOUT(0x776AA2);
}
