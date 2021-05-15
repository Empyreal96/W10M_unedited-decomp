// PoFxRegisterPlugin 
 
int __fastcall PoFxRegisterPlugin(unsigned __int16 *a1, unsigned __int16 *a2)
{
  return PopFxRegisterPluginEx(a1, (int)a2, 0, 0, a2);
}
