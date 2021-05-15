// sub_7E0C4C 
 
void sub_7E0C4C()
{
  unsigned int v0; // r5
  unsigned int v1; // r7

  v1 = *(_DWORD *)(v0 + 12);
  if ( v1 )
  {
    (*(void (__fastcall **)(_DWORD))(v1 + 12))(*(_DWORD *)(v1 + 4));
    ExFreePoolWithTag(v1);
  }
  ExFreePoolWithTag(v0);
  JUMPOUT(0x777C7A);
}
