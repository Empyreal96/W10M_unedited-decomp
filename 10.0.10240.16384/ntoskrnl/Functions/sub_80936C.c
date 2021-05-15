// sub_80936C 
 
void sub_80936C()
{
  int v0; // r5
  int v1; // r7

  if ( ExfAcquireRundownProtection((_DWORD *)(v0 + v1)) )
    JUMPOUT(0x75D472);
  JUMPOUT(0x75D534);
}
