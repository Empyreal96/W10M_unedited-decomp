// sub_7CDC30 
 
void __fastcall sub_7CDC30(_DWORD *a1)
{
  int v1; // r4
  _DWORD *v2; // r6

  if ( v1 && v1 == *a1 && *a1 >= 4u )
  {
    *v2 = a1;
    JUMPOUT(0x7726FC);
  }
  JUMPOUT(0x7726FA);
}
