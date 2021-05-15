// MmStrongCodeGuaranteesEnforced 
 
BOOL MmStrongCodeGuaranteesEnforced()
{
  return (MiFlags & 0x30000) != 0;
}
