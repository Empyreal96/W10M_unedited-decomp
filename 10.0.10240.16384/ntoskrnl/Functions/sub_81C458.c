// sub_81C458 
 
void __fastcall sub_81C458(unsigned int a1)
{
  int v1; // r5

  *(_DWORD *)(v1 + 32) = 0;
  if ( a1 )
    ExFreePoolWithTag(a1);
  JUMPOUT(0x7BC75A);
}
