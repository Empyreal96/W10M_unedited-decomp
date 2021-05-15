// sub_552F68 
 
void __fastcall sub_552F68(int a1)
{
  int v1; // r6
  int v2; // r4

  if ( (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) == *(_DWORD *)(v1 + 80) )
    v2 = EtwActivityIdControl(1, (int *)(a1 + 12));
  else
    v2 = -1073741637;
  if ( v2 < 0 )
    IopFreeIrpExtension(v1, 0, 1);
  JUMPOUT(0x4F2E68);
}
