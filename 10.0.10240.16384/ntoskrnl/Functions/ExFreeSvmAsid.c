// ExFreeSvmAsid 
 
int ExFreeSvmAsid()
{
  int result; // r0

  if ( *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 740) )
    result = sub_5269EC();
  return result;
}
