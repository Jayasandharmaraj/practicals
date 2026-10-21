export module pipeline;
import <vector>;
import <concepts>;
import <ranges>;

export template<typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

export template<Numeric T>
std::vector<T> processData(const std::vector<T>& data) {
    std::vector<T> result;
    auto pipeline = data
        | std::views::filter([](T value) { return value > 0; })
        | std::views::transform([](T value) { return value * 2; });
    for (T value : pipeline) result.push_back(value);
    return result;
}
