// MmDbgMarkPfnModifiedWorker 
 
int MmDbgMarkPfnModifiedWorker()
{
  int *v0; // r5
  int v1; // r6
  int result; // r0

  v0 = &dword_634590;
  v1 = 32;
  while ( (*v0 & 1) == 0 )
  {
    ++v0;
    if ( !--v1 )
      return result;
  }
  return sub_554924();
}
