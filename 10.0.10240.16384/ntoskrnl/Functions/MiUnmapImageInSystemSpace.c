// MiUnmapImageInSystemSpace 
 
int __fastcall MiUnmapImageInSystemSpace(unsigned int *a1)
{
  int result; // r0

  if ( *a1 > MmHighestUserAddress )
    result = MiRemoveFromSystemSpace((int)algn_632F64, *a1, 1);
  else
    result = sub_7D4FA0();
  return result;
}
