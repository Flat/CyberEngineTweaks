#pragma once

struct Scripting;

struct Sandbox
{
    Sandbox(Scripting* apScripting, sol::environment aBaseEnvironment, const std::filesystem::path& acRootPath);
    ~Sandbox() = default;

    sol::protected_function_result ExecuteFile(const std::string& acPath) const;
    sol::protected_function_result ExecuteString(const std::string& acString) const;

    sol::environment& GetEnvironment();
    sol::table& GetImGui();
    const std::filesystem::path& GetRootPath() const;

private:
    Scripting* m_pScripting;
    sol::environment m_env;
    sol::table m_imgui;
    std::filesystem::path m_path{ };
};