// PopEsUpdateSetting 
 
int PopEsUpdateSetting()
{
  ZwUpdateWnfStateData();
  return PopTraceEsSetting(PopEsMode, dword_61EC50, (unsigned __int8)byte_61EC54);
}
