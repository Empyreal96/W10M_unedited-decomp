// MiDereferenceImports 
 
unsigned int __fastcall MiDereferenceImports(unsigned int result)
{
  unsigned int *v1; // r4
  unsigned int v2; // r5
  unsigned int v3; // r7
  unsigned int v4; // r6
  unsigned int v5; // t1

  v1 = (unsigned int *)result;
  if ( result != 1 && result != -2 )
  {
    if ( (result & 1) != 0 )
    {
      result = sub_7CE974();
    }
    else
    {
      v2 = 0;
      if ( *(_DWORD *)result )
      {
        v3 = result;
        do
        {
          v5 = *(_DWORD *)(v3 + 4);
          v3 += 4;
          v4 = v5;
          if ( !v5 )
            break;
          result = MiUnloadApproved(v4);
          if ( result == 1 )
            result = MiUnloadSystemImage(v4, -1);
          ++v2;
        }
        while ( v2 < *v1 );
      }
    }
  }
  return result;
}
