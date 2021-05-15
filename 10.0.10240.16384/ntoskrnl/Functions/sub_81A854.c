// sub_81A854 
 
void __fastcall sub_81A854(_DWORD *a1)
{
  int v1; // r5
  int v2; // r6

  if ( *a1 != v1 )
  {
    ExFreePoolWithTag((unsigned int)a1);
    *(_DWORD *)(v2 + 3216) = 0;
    JUMPOUT(0x7B7D94);
  }
  JUMPOUT(0x7B7DC4);
}
