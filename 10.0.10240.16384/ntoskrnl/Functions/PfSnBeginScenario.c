// PfSnBeginScenario 
 
int PfSnBeginScenario()
{
  unsigned int v1; // [sp+30h] [bp-38h]

  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  __mrc(15, 0, 13, 0, 3);
  *(_BYTE *)(v1 + 346) = 0;
  if ( (*(_DWORD *)(*(_DWORD *)(v1 + 336) + 192) & 0x100000) == 0 )
    JUMPOUT(0x80871E);
  return sub_808718();
}
