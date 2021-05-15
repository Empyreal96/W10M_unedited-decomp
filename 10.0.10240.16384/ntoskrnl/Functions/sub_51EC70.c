// sub_51EC70 
 
void __fastcall sub_51EC70(int a1)
{
  if ( *(_DWORD *)(a1 + 44) != a1 + 44 )
  {
    FsRtlLookupPerStreamContextInternal();
    JUMPOUT(0x44E0FC);
  }
  JUMPOUT(0x44E10A);
}
