// KiInitializeExceptionVectorTable 
 
void KiInitializeExceptionVectorTable()
{
  __mcr(15, 0, (unsigned int)KiArmExceptionVectors & 0xFFFFFFFE, 12, 0, 0);
  __isb(0xFu);
  __mcr(15, 0, __mrc(15, 0, 1, 0, 0) & 0xFFFFDFFF, 1, 0, 0);
  __isb(0xFu);
}
