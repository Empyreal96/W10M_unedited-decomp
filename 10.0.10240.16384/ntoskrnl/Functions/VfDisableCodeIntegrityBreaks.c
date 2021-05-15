// VfDisableCodeIntegrityBreaks 
 
void VfDisableCodeIntegrityBreaks()
{
  int *v0; // r3

  v0 = &ViCiDefaultActions;
  do
    *v0++ = 2;
  while ( v0 != (int *)&ViFnXdvQueryDispatchTable );
}
