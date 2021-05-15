// MmImageSectionPagable 
 
int __fastcall MmImageSectionPagable(int *a1)
{
  int v2; // r1
  int result; // r0
  int v4; // r1

  v2 = *a1;
  result = 0;
  if ( v2 == 1633969454 )
    return 1;
  if ( v2 == 1162297680 )
  {
    v4 = *((unsigned __int8 *)a1 + 4);
    result = 1;
    if ( v4 == 75 && *((_BYTE *)a1 + 5) == 68 )
    {
      result = (unsigned __int8)KdPageDebuggerSection;
    }
    else if ( v4 == 86 && *((_BYTE *)a1 + 5) == 82 && *((_BYTE *)a1 + 6) == 70 && (MiFlags & 1) != 0 )
    {
      result = 0;
    }
  }
  return result;
}
